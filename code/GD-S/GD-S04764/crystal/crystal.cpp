#include<bits/stdc++.h>
using namespace std;
int n,m,s,u,j,f,pin,num=0,c=0;
int a[10001],b[10001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	u=m;
	j=m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	for(int i=0;i<n;i++){
		for(int k=1;k<n;k++){
			if(a[k]>a[k+1]){
				f=a[k];
				a[k]=a[k+1];
				a[k+1]=f;
			}
		}
	}
	for(int l=u;l>=0;l--){
		s=l;
		for(int i=0;i<n;i++){
			for(int t=0;t<n;t++){
				b[t]=a[t];
			}
			for(int k=i;k<n;k++){
				b[k]+=s;
				s=j-s;
				j=s;
			}
			for(int k=0;k<n;k++){
				pin=b[k];
				for(int t=0;t<n;t++){
					if(b[t]==pin) num++;
				}
				if(num>=c) c=num;
				num=0;
			}
			j=m;
			s=l;
		}
		u--;
	}
	cout<<c;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
