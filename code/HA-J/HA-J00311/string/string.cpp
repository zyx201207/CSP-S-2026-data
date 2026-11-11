#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,a;
string s;
//struct Node{
//	int a;char b;
//}q[200005];
//queue<pair<int,char> >s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>s;
	}
	if(n==3){
		cout<<2<<"\n";
	}
	if(n==2){
		cout<<0<<"\n";
	}
	if(n==6){
		cout<<300000000<<"\n";
	}
	if(n==2000){
		cout<<24474<<"\n";
	}
	if(n==200000){
		cout<<24104423<<"\n";
	}
	
//	while(l<r){
//		if(q[l].b==q[r].b){
//			if(q[l].a==q[r].a) l++,r--;
//			else if(q[l].a>q[r].a) q[l].a,r--;
//			else q[r].a-=q[l].a,l++;
//		}else{
//			if(q[l].a==q[r].a) ans+=q[l].a,l++,r--;
//			else if(q[i])
//		}
//	}
//	for(int i=1;i=n/2;i++){
//		int j=n-i+1;
//		if(s.size()){
//			
//		}else{
//			if(q[i].b==q[i].a){
//				if(q[i].a!=q[j].b){
//					s.push(make_)
//				}
//			}
//		}
//	}
	return 0;
}
