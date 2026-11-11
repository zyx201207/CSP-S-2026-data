#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+1,M=3*1e5;
int n,m,num[N];
string s;
struct Node{
	int x;
	int cnt;
}a[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>num[i];
	for(int i=0;i<n;i++){
		string s1;
		for(int j=0;j<n-i;j++){
			s+=num[i]+'0';
			s1+=num[i]+'0';
		}
		//int p=s.find(num[i]),q=s.find(num[i]);
		//s.erase(p,q);
	}
	for(int i=0;i<m;i++) cout<<a[i].cnt<<" ";
	return 0;
}
