#include<bits/stdc++.h>

using namespace std;
long long n,m,a[200005],maxx=INT_MIN,b[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++)cin>>a[i];
	sort(a,a+n,greater<long long>());
	for(long long i=0;i<n-m+1;i++){
		long long j=i+1,k=1,c=a[i];
		memset(b,0,sizeof(b));
		for(;j<n;j++){
			if(k<m){
				if(b[j]==1)j++;
				else{				
					c&=a[j];
					b[j]=1;
					k++;
				}
			}
			else{
				maxx=max(maxx,c);
				memset(b,0,sizeof(b));
				k=0;
			}
		}
	}
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
