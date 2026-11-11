#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=2e5+10;
struct node{
	int a;
	char c;
}arr2[N];
struct node2{
	int a;
	char c;
}arr[N];
int n,len=0,ans=0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr2[i].a>>arr2[i].c;
		if(arr2[i].c==arr2[i-1].c&&i!=1){
			arr[len].a+=arr2[i].a;
		}else{
			arr[++len].a=arr2[i].a;
			arr[len].c=arr2[i].c;
		}
	}
	int l=1,r=len;
	while(l<=r){
		if(arr[l].c!=arr[r].c){
			if(arr[l].a==arr[r].a){
				ans+=arr[r].a;
				l++;
				r--;
			}
			else if(arr[l].a>arr[r].a){
				arr[r].c=arr[l].c;
				ans+=arr[r].a;
				arr[l].a-=arr[r].a;
				r--;
			}
			else{
				arr[l].c=arr[r].c;
				ans+=arr[l].a;
				arr[r].a-=arr[l].a;
				l++;
			}
		}
		else{
			if(arr[l].a==arr[r].a){
				l++;
				r--;
			}
			else if(arr[l].a>arr[r].a){
				arr[l].a-=arr[r].a;
				r--;
			}
			else{
				arr[r].a-=arr[l].a;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}

