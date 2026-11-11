#include<bits/stdc++.h>

#define problem(prob) freopen(#prob ".in","r",stdin),freopen(#prob ".out","w",stdout)
#define stm() std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)

#ifndef int64_t
typedef long long int64_t;
#endif

const char endl='\n';

int64_t pos[2000005];
int64_t n,d,ans=0;

struct findinfo{
	short rands=-1;
	short length=0;
	findinfo(short r,short l){
		rands=r;
		length-l;
	}
	findinfo(){}
};

std::map<std::pair<int64_t,int>,findinfo> rem;

findinfo tryfind(int64_t posa,int64_t posb){
	if(rem.find(std::pair<int64_t,int>(posa,posb-posa))!=rem.end()){
		return rem[std::pair<int64_t,int>(posa,posb-posa)];
	}
//		std::cout<<"#?"<<pos[posa]<<","<<pos[posb]<<endl;
	if(pos[posb]-pos[posa]<=d)return findinfo(1,1);
//		std::cout<<"#!"<<posa<<","<<posb<<endl;
	if(posb-posa==1)
		return findinfo(0,0);
	int mini=0;
	int rands=0;
	for(int i=posa+1;i<posb;i++){
		findinfo a=tryfind(posa,i);
		findinfo b=tryfind(i,posb);
		if(!a.rands)continue;
		if(!b.rands)continue;
		if(!rands){
			mini=a.length+b.length;
			rands=a.rands*b.rands;
		}else{
			int l=a.length+b.length;
			if(l<mini){
				rands=a.rands*b.rands;
				mini=l;
			}else if(l==mini){
				rands+=a.rands*b.rands;
			}
		}
//		std::cout<<"# TRY "<<posa<<"->"<<i<<"->"<<posb<<", mini="<<mini<<" rand="<<rands<<endl;
	}
	if(rands==2)ans++;
//	if(rands==2)std::cout<<"# ANS "<<posa+1<<"->"<<posb+1<<endl;
	return rem[std::pair<int64_t,int>(posa,posb-posa)]=findinfo(rands,mini);
}

int main(){
	problem(migrate);
	stm();
	
	int C,T;
	std::cin>>C>>T;
	
	while(T--){
		std::cin>>n>>d;
		ans=0;
		rem.clear();
		for(int i=0;i<n;i++){
			std::cin>>pos[i];
		}
		tryfind(0,n-1);
		std::cout<<ans<<endl;
	}
	
	return 0;
} 
