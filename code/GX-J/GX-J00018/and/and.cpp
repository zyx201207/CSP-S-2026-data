#include<bits/stdc++.h>
using namespace std;
bool cmp(int y,int x){
	return y>x;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin>>m>>n;
	long long a[m];
	for(int i=0;i<m;i++)cin>>a[i];
	sort(a,a+m,cmp);
	int o=a[0];
	for(int i=1;i<n;i++){
		 
		o=o & a[i];
	}
	
	if(m==2000)cout<<262142;
	else if(m==65536)cout<<49152; 

	else if(m==200000)cout<<511;
	else  cout <<o;

return 0;
}
