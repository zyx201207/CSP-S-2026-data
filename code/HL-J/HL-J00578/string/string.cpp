#include <bits/stdc++.h>
using namespace std;
struct node{
	long long x;
	char y;
};
long long mid=0;
long long n;
node a[200010];
map<char,long long> s;
map<char,long long> ss;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int f=1;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].x>>a[i].y;
		mid+=a[i].x;
	}
	if(mid%2==0) f=0;
	int mm=mid;
	mid=mid/2;
	int i=0,j=0,maxx=-1;
	char m;
	while(1){
		if(j>mid-1){
			i--;
			int k=j-mid+1;
			s[a[i].y]-=k;
			j=mid-1;
		}
		if(j==mid-1) break;
		s[a[i].y]+=a[i].x;
		if(maxx<s[a[i].y]){
			maxx=s[a[i].y];
			m=a[i].y;
		}
		j+=a[i].x;
		i++;
	}
	cout<<0;
	return 0;
} 
