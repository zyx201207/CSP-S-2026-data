//shapaoziAC
#include<bits/stdc++.h>
using namespace std;
long long n,m;
vector<long long>a,cha,quan;
bool dengcha=1;
long long dengchashu;
long long res;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin.tie(0);
	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		long long x;
		cin>>x;
		a.push_back(x);
		quan.push_back(0);
	}
	for(int i=0;i<n-1;i++){		
		cha.push_back(0);
	}
	sort(a.begin(),a.end());
	for(int i=0;i<n-1;i++){
		cha[i]=a[i+1]-a[i];
		///cout<<cha[i];
	}
	for(int i=0;i<n-2;i++){
		if(cha[i]!=cha[i+1]){//feidengcha
			dengcha=0;
			break;
		}else{//dengcha
			continue;
		}
	}
	if(dengcha){//等差数列处理 AB
		for(int i=0;i<n-1;i++){
			dengchashu = dengchashu+cha[i]*(i+1);
			if(dengchashu<=m){
				quan[0]++;
			}else{
				i=n-1;
			}
			
		}
		
	}else{//非等差数列处理 
		for(int i=0;i<n-1;i++){//第一层数进位 
		long long test=0;
		long long chengshu=1;
		for(int j=i;j<n-1;j++){//第二层加权 
			
			test=test + cha[j]*chengshu;
			if(test<=m){
				chengshu++;
				quan[i]++;
			}else{
				j=n-1;
			}
			
		} 
	}
	sort(quan.begin(),quan.end(),greater<int>());
	
	}
	res=quan[0]+1;
	cout<<res;
	return 0;

}
