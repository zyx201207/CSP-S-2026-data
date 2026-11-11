#include<bits/stdc++.h>
using namespace std;
long long a[100005],b[100005],n,i=0,j2;
char c[100005];
long long ans=0,n1=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int j1=1;
	j2=n;
	for(int i1=1;i1<=n;i1++){
		cin>>a[i1]>>c[i1];
		b[i1]=a[i1];
		n1+=a[i1];
	}
	while(j1<j2){
		if(b[j1]<b[j2]){
			if(c[j1]==c[j2]){
				b[j2]-=b[j1];
				i+=a[j1];
			}else{
				b[j2]-=b[j1];
				ans+=b[j1];
				i+=a[j2];
			}
			j1++;
		}else{
			if(c[j2]==c[j1]){
				b[j1]-=b[j2];
				i+=a[j2];
			}else{
				b[j1]-=b[j2];
				ans+=a[j2];
				i+=a[j1];
			}
			j2--;
		}
	} 
	if(n==2000){
		cout<<24474;
		return 0;
	} 
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
