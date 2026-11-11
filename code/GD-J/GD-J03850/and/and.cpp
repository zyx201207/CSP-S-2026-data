#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long a,b;
	cin>>a>>b;
	long long k[a];
	if(b==2){
		long long max1=-99999;
		for(int i=0;i<a-1;i++){
			for(int j=i;j<a;j++){
				long long ls=k[i]&k[j];
				if(ls>max1){
					max1=ls;
				}
			}
		}
		cout<<max1<<endl;
	}
	if(b==3){
		long long max1=-99999;
		for(int i=0;i<a-2;i++){
			for(int u=i;u<a-1;u++)
			for(int j=u;j<a;j++){
				long long ls=k[i]&k[j]&k[u];
				if(ls>max1){
					max1=ls;
				}
			}
		}
		cout<<max1<<endl;
	}
	if(b==4){
		long long max1=-99999;
		for(int i=0;i<a-3;i++){
			for(int u=i;u<a-2;u++)
			for(int g=u;g<a-1;g++)
			for(int j=g;j<a;j++){
				long long ls=k[i]&k[j]&k[u]&k[g];
				if(ls>max1){
					max1=ls;
				}
			}
		}
		cout<<max1<<endl;
	}
	if(b==5){
		long long max1=-99999;
		for(int i=0;i<a-4;i++){
			for(int u=i;u<a-3;u++)
			for(int g=u;g<a-2;g++)
			for(int z=g;z<a-1;z++)
			for(int j=z;j<a;j++){
				long long ls=k[i]&k[j]&k[u]&k[g]&k[z];
				if(ls>max1){
					max1=ls;
				}
			}
		}
		cout<<max1<<endl;
	}
	if(b==6){
		long long max1=-99999;
		for(int i=0;i<a-5;i++){
			for(int u=i;u<a-4;u++)
			for(int g=u;g<a-3;g++)
			for(int z=g;z<a-2;z++)
			for(int l=z;l<a-1;l++)
			for(int j=l;j<a;j++){
				long long ls=k[l]&k[i]&k[j]&k[u]&k[g]&k[z];
				if(ls>max1){
					max1=ls;
				}
			}
		}
		cout<<max1<<endl;
	}
}
