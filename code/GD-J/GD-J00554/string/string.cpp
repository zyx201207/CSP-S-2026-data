#include<bits/stdc++.h>
using namespace std;
struct t{
	long long a;
	char b;
} f[200100];
long long sum=0,i=1,j,n,l,t=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>f[i].a>>f[i].b;
		l+=f[i].a;
	}
	j=n;
	for(;t<=l;){
		if(f[j].a==f[i].a){
			if(f[i].b!=f[j].b) sum+=f[i].a;
			t+=f[i].a;
			f[j].a=0;
			f[i].a=0;
			i++;
			j--;
		}
		if(i>=j) break;
		
		while(f[j].a<f[i].a){
			if(f[j].b==f[i].b){
				f[i].a-=f[j].a;
			}
			else{
				f[i].a-=f[j].a;
				sum+=f[j].a;
			}
			j--;
			if(i>=j) break;
			t+=f[j].a;
		}
		if(i>=j) break;
		
		while(f[i].a<f[j].a){
			if(f[i].b==f[j].b){
				f[j].a-=f[i].a;
			}
			else{
				f[j].a-=f[i].a;
				sum+=f[i].a;
			}
			i++;
			if(i>=j) break;
			t+=f[i].a;
		}
		if(i>=j) break;
	}
	cout<<sum;
	return 0;
} 
