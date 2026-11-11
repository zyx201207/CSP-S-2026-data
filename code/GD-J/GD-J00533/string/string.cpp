#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,ans;
struct node{
	long long a;
	char c;
}arr[N];
int main(){
    freopen("string.out","r",stdin);
    freopen("string.in","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
	cin>>arr[i].a>>arr[i].c;
    long long l=1,r=n,k;
   	while(l<=r){
   		k=min(arr[l].a,arr[r].a);
   		arr[l].a-=k;
   		if(l!=r)
   	 	arr[r].a-=k; 
   		if(arr[l].c!=arr[r].c)		
    	ans+=k;
   		if(arr[l].a<=0) 
   		l++;
    	if(arr[r].a<=0)
    	r--;
	}cout<<ans;
    cout.flush();
    return 0;
}
