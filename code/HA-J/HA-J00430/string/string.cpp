





#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	//ios::sync_with_stdio(0),cin.tie(0);
	
	int n;
	long long ans=0;
	cin>>n;
	vector<int> shu(n+2);
	vector<char> zm(n+2);
	
//	shu.push_back(0);
//	zm.push_back('a');
		
	for(int i=1;i<=n;i++){
		int a;
		char b;
		cin>>shu[i]>>zm[i];
//		shu.push_back(a);
//		zm.push_back(b);
	}
	
	int j=n,sysl=shu[1];//shengyushuliang
	char syzf=zm[1],bj='i';
	
	for(int i=1;i<=n;){
		
		if(i==j){
			cout<<ans;
			return 0;
		}
		
		if(bj=='i'){
			if(sysl>=shu[j]){
				
				//cout<<syzf<<' '<<zm[j]<<endl;
				
				sysl=sysl-shu[j];
				if(syzf!=zm[j]){
					ans+=shu[j];
					
					//cout<<shu[j]<<' ';
					//cout<<'<'<<'>';//zhushi
					
					
				}
				j--;
			}else{
				
				if(syzf!=zm[j]){
					ans+=sysl;
					
					//cout<<shu[j]<<' ';
					
					syzf=zm[j];
				}
				sysl=shu[j]-sysl;
				bj='j';
				i++;
			}
		}else if(bj=='j'){
			
			if(sysl>=shu[i]){
				sysl=sysl-shu[i];
				if(syzf!=zm[i]){
					ans+=shu[i];
					
					//cout<<shu[j]<<' ';
				}
				i++;
			}else{
				
				if(syzf!=zm[i]){
					ans+=sysl;
					
					//cout<<shu[j]<<' ';
					
					syzf=zm[i];
				}
				sysl=shu[i]-sysl;
				bj='i';
				j--;
			}	
		}
	}
	
	
	return 0;
}

//3
//2 a
//2 b
//1 c

//2
//2 a
//3 a

//6
//1000000000 a
//1000000000 a
//1000000000 a
//1000000000 b
//1000000000 b
//1000000000 b













