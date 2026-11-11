#include <bits/stdc++.h>
using namespace std;
long long n,f,a[200005],b[200005],su;
char c[200005],d[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		if(d[f]==c[i]){
			b[f]+=a[i];
		}
		else{
			f++;
			d[f]=c[i];
			b[f]=a[i];
		}
	}
	int i=1;
	while(i<f){
		if(d[i]==d[f]){
			if(b[i]==b[f]){
				i++;
				f--;
			}
			else{
				long long ls,lss;
				lss=(max(b[i],b[f])==b[i])?1:0;
				if(lss){
					ls=b[i]-b[f];
					b[i]=ls;
					f--;
				}
				else{
					ls=b[f]-b[i];
					b[f]=ls;
					i++;
				}
			}
		}
		else{
			if(b[i]==b[f]){
				i++;
				f--;
				su+=b[i];
			}
			else{
				long long ls,lss;
				lss=(max(b[i],b[f])==b[i])?1:0;
				su+=min(b[f],b[i]);
				if(lss){
					ls=b[i]-b[f];
					b[i]=ls;
					f--;
				}
				else{
					ls=b[f]-b[i];
					b[f]=ls;
					i++;
				}
			}
		}
	}
	cout<<su;
	

	return 0;
} 
