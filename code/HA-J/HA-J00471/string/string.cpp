#include<bits/stdc++.h>
using namespace std;
struct node{
	int m;
	char s;
}a[200005];
long long sum,n,k;
string b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].m>>a[i].s;
		for(int j=1;j<=a[i].m;j++){
			b+=a[i].s;
		}
	}
	long long len=b.size();
	long long l=0,r=len-1;
	while(r>=l){
		if(b[l]==b[r]){
			l++;
			r--;
			continue;
		}
		if(b[l+1]==b[l]){
			char c=b[l+1];
			b[l+1]=b[r];
			b[r]=c;
			sum++;
		}
		else if(b[r]==b[r-1]){
			char c=b[l];
			b[r-1]=b[l];
			b[l]=c;
			
			sum++;
		}
		l++;
		r--;
	}
	cout<<sum<<"\n";
	return 0;
} 
