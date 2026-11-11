#include<bits/stdc++.h>
using namespace std;
const int N=2e5+15;
int a[N]; 
int dna(int a,int b){
	int c[22],d[22],cnt=0;
	for(int i=1;i<=22;i++){
		c[i]=0,d[i]=0;
	}
	for(int i=1;i<=22;i++){
		if(a>0){
		c[i]=a%2;
		a/=2;
	}
	if(b>0){
		d[i]=b%2;
		b/=2;
			}
	}
	for(int i=1;i<=22;i++){
		if(c[i]==1&&d[i]==1){
				cnt+=pow(2,i-1);
	}
	}
	return cnt;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,cnt=0,mx=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<=22;j++){
			if(a[i]==pow(2,j)-1){
				cnt++;
				break;
			}
		}
	}
	sort(a+1,a+1+n);
	if(m==n){
	mx=a[1];
	for(int i=2;i<=n;i++){
	mx=dna(mx,a[i]);
	}
	cout<<mx;
	return 0;
	}
	if(m==1){
		cout<<a[n];
		return 0;
	}
    if(m==2){
    	for(int i=1;i<=n-1;i++){
    		for(int j=i+1;j<=n;j++){
    			if(dna(a[i],a[j])>=mx){
    				mx=dna(a[i],a[j]);
				}
			}
		}
		cout<<mx;
		return 0;
	}
	if(cnt==n){
		cout<<a[n-m+1];
		return 0;
	}
    if(m==n-1){
    	mx=a[1];
	for(int i=2;i<=n;i++){
	mx=dna(mx,a[i]);
	}
	int d[N];
	for(int i=1;i<=n;i++){
		d[i]=mx||a[i];
	}
	mx=0;
	for(int i=1;i<=n;i++){
		if(d[i]>=mx){
			mx=d[i];
		}
	}
	cout<<mx;
	}
	if(n<=20){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
			    for(int k=j+1;k<=n;k++){
			    	if(dna(a[i],dna(a[j],a[k]))>mx){
			    		mx=dna(a[i],dna(a[j],a[k]));
					}
				}
			}
		}
		cout<<mx;
		return 0;
	}
	return 0;
} 
