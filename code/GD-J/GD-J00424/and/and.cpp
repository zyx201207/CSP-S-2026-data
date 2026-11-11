#include<bits/stdc++.h>
using namespace std;
int n,m;
long long p[35],a[200050],q,sum=0; 
bool b[200050];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	memset(b,true,sizeof(b));
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	p[0]=1;
	for(int i=1;i<=30;i++){
		p[i]=p[i-1]*2;
		if(p[i]>a[n-1]){
			q=i;
			break;
		}
	}
	for(int i=q;i>=0;i--){
		int s=0;
		for(int j=0;j<n;j++){
			if(a[j]>=p[i]&&b[j]){
				s++;
			}
		}
		if(s>=m){
			sum+=p[i];
			for(int j=0;j<n;j++){
				if(a[j]>=p[i]&&b[j]){
					a[j]-=p[i];
				}else{
					b[j]=false;
				}
			}
		}else{
			for(int j=0;j<n;j++){
				if(a[j]>=p[i]&&b[j]){
					a[j]-=p[i];
				}
			}
		}
		
	}
	cout<<sum<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
