#include<bits/stdc++.h>
using namespace std;
long long a,ma,b,c[100000005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>c[i];
	}
	sort(c,c+a-1);
	if(b==1){
		cout<<c[a-1];
		return 0;
	}
	if(b==2){
		for(long long i=0;i<a-1;i++){
			for(long long j=i+1;j<a;j++){
				long long z1=c[i] & c[j];
				ma=max(ma,z1);
			}
		}
		cout<<ma;
		return 0;
	}
	if(b==3){
		for(long long i=0;i<a-2;i++){
			for(long long j=i+1;j<a-1;j++){
				for(long long z=j+1;z<a;z++){
					long long z1=c[i] & c[j] & c[z];
					ma=max(ma,z1);
				}
			}
		}
		cout<<ma;
		return 0;
	}
	if(b==4){
		for(long long i=0;i<a-3;i++){
			for(long long j=i+1;j<a-2;j++){
				for(long long z=j+1;z<a-1;z++){
					for(long long w=z+1;w<a;w++){
						long long z1=c[w] & c[i] & c[j] & c[z];
						ma=max(ma,z1);
					}
				}
			}
		}
		cout<<ma;
		return 0;
	}
	return 0;
} 
