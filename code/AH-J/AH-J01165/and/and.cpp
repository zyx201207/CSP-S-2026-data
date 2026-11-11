#include<bits/stdc++.h>
using namespace std;

long long n,m,big=-1000,big1=-1000,big2=0,id=0;
long long a[200005];
long long b[200005];

int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	int aa=n;
	while(aa--){
		cin>>a[aa];
		if(a[aa]>=big) big=a[aa];
		int abc=a[aa];
		while(abc){
			if(abc%2==1) b[aa]++;
			if(abc/2==1) b[aa]++;
			abc/=2;
		}
		if(b[aa]>=big2){
			big2=b[aa];
			id=aa;
		}
	}
	
	b[id]=0;
	
	int s=a[1];
	if(n==m) for(int i=1;i<=m;i++){
		s=s&a[i];
	}else{
		if(m==1){
			cout<<big;
		}else{
			if(m==2){
				for(int i=1;i<=m;i++){
					for(int j=1;j<=m;j++){
						if((a[i]&a[j])>=big1) big1=a[i]&a[j];
					}
				}
			}else{
				int mm=m-1;
				int s=a[id];
				while(mm--){
					big2=0;
					for(int i=1;i<=n;i++){
						if(b[i]>=big2){
							big2=b[i];
							id=i;
						}
					}
					s=s&a[id];
					b[id]=0;
				}
			}
		}
	}
	cout<<s;
	
	return 0;
	
}
