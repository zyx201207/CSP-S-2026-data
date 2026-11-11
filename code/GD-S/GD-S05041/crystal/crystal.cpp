#include<bits/stdc++.h>

using namespace std;
const long long N=1e12+3;
typedef long long ll;
ll m;
int n,a[10001],q,ma[N],s=0,o;
void lesson(){
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	
		for(int i=1;i<=n;i++){
			ma[i]=1;
			
			for(int j=m;j>=1;j--)
			{	
				q=a[i];
				q+=j;
				s=m-j;
				o=a[i+1];
				if(s>=1)o+=s;
				for(int i=1;i<=n;i++)
				if(q==o)
				{	
					ma[i]+=1;
				}
		
			}
	}
		sort(ma+1,ma+1);
		cout<<ma[1];
			
	}
	
		
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	lesson();
	
	
	
	return 0;
} 
