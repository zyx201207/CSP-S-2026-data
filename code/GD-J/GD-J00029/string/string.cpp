#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],b[200010],sum=0,e,f,h=1,k=1,cnt=0,s=0;
char c[200010],d[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	int fl=0;
	for(int i=n,j=1;i>=1;i--,j++){
		b[j]=a[i];
		d[j]=c[i];
		cnt+=a[i];
		if(cnt>sum/2&&fl==0){
			f=i;
			e=j;
			fl=1;
		}
		if(cnt==sum/2&&fl==0){
			f=i;
			e=j;
			fl=2;
		}
	}
	if(fl==1){
		while(h!=f||k!=e){
			if(c[h]!=d[k]){
				if(a[h]==b[k]){
					s+=a[h];
					h++;
					k++;
				}else if(a[h]<b[k]){
					b[k]-=a[h];
					s+=a[h];
					h++;
				}else{
					a[h]-=b[k];
					s+=b[k];
					k++;
				}
			}else{
				if(a[h]==b[k]){
					h++;
					k++;
				}else if(a[h]<b[k]){
					b[k]-=a[h];
					h++;
				}else{
					a[h]-=b[k];
					k++;
				}
			}
		}
	}else{
		while(h<=f&&k<=e){
			if(c[h]!=d[k]){
				if(a[h]==b[k]){
					s+=a[h];
					h++;
					k++;
				}else if(a[h]<b[k]){
					b[k]-=a[h];
					s+=a[h];
					h++;
				}else{
					a[h]-=b[k];
					s+=b[k];
					k++;
				}
			}else{
				if(a[h]==b[k]){
					h++;
					k++;
				}else if(a[h]<b[k]){
					b[k]-=a[h];
					h++;
				}else{
					a[h]-=b[k];
					k++;
				}
			}
		}
	}
	cout<<s;
	return 0;
} 
