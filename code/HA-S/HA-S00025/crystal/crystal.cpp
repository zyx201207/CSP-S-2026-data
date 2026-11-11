#include<bits/stdc++.h>
using namespace std;
long long n,m,mid,j,cha=0;
const int N=100005;
int shuzu[N];
int main(){
	freopen("crystal.in","r",stdin);
		freopen("crystal.out","w",stdout);
		cin>>n>>m;
		shuzu[0]=0;
		for(int i=1;i<=n;++i) cin>>shuzu[i];
	sort(shuzu,shuzu+(n+1));
	
mid=(1+n)/2;
while(cha<m){
	for(j=0;j<mid;j++)
	cha=cha+(shuzu[mid]-shuzu[j]); 
}
for(int i=mid;i<n;i++){
	if(shuzu[i]==mid) j++;
} 
cout<<j;

	fclose(stdin);
	fclose(stdout);
	return  0;
} 
