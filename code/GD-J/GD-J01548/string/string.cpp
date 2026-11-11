#include<bits/stdc++.h>
using namespace std;
struct node{
	char c;
	long long len;
}a[200001];
long long n,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].len>>a[i].c;
	int l=1,r=n;
	while(l<=r){
		if(a[l].c==a[r].c){
			if(a[l].len>a[r].len) a[l].len-=a[r].len,r--;
			else if(a[l].len<a[r].len) a[r].len-=a[l].len,l++;
			else l++,r--;
		}
		else{
			if(a[l].len>a[r].len) a[l].len-=a[r].len,ans+=a[r].len,r--;
			else if(a[l].len<a[r].len) a[r].len-=a[l].len,ans+=a[l].len,l++;
			else ans+=a[r].len,l++,r--;
		}
	}
	cout<<ans; 
}/*6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
