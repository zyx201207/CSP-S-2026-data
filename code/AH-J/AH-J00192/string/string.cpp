#include<bits/stdc++.h>
using namespace std;
int n;long long a[214514],c[214514];char b[214514];
int main(){
	freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	long long s=0;
	ios::sync_with_stdio(0);
	cin>>n;for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];s+=a[i];
		c[i]=c[i-1]+a[i];
	}long long l=1,r=s,k=1,m=n,as=0;
	while(l<r){
		if(b[k]==b[m]){
			if(c[k]+1-l<r-c[m-1]){
				r-=c[k]+1-l;l=c[k]+1;
				k++;//cout<<'a';
			}else if(c[k]+1-l>r-c[m-1]){
				l+=r-c[m-1];r=c[m-1];
				m--;//cout<<'b';
			}else{
				r-=c[k]+1-l;l=c[k]+1;
				k++;m--;//cout<<'f';
			}
		}else{
			if(c[k]+1-l<r-c[m-1]){as+=c[k]+1-l;
				r-=c[k]+1-l;l=c[k]+1;
				k++;//cout<<'c';
			}else if(c[k]+1-l>r-c[m-1]){as+=r-c[m-1];
				l+=r-c[m-1];r=c[m-1];
				m--;
				//cout<<'d';
			}else{as+=c[k]+1-l;
				r-=c[k]+1-l;l=c[k]+1;
				k++;m--;//cout<<'e';
			}
		}
	//	cout<<l<<' '<<r<<' '<<as<<' '<<m<<' '<<k<<endl;
	}cout<<as;
	return 0;
} 
