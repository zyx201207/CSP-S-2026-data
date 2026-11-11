#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct node{
	int num;
	char c;
}arr[N];
int n;
int find(int s){
	int d=0;
	for(int i=0;i<n;i++){
		if(d<=s&&d+arr[i].num>=s){
			return i;
		}else{
			d+=arr[i].num;
		}
	}
}
int main(){

	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	int l=0;
	
	for(int i=0;i<n;i++){
		cin>>arr[i].num>>arr[i].c;
		l+=arr[i].num;
	}
	int ans=0;
	for(int i=1;i<=l/2;i++){
		
		if(arr[find(i)].c!=arr[find(l-i+1)].c){
			
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
