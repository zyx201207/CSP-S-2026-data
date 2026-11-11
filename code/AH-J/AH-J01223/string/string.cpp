#include<bits/stdc++.h>
using namespace std;
struct node{
	int a;
	char c;
	void input(){
		cin>>a>>c;
	}
};
long long res=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	vector<node> no(n);
	for(int i=0;i<n;i++) no[i].input();
	vector<node> t=no;
	reverse(t.begin(),t.end());
	for(int i=0;i<n;i++){
		if(t[i].a<no[i].a){
			if(t[i].c!=no[i].c) res+=no[i].a-t[i].a;
			no[i].a=t[i].a;
		}
		if(t[i].a>no[i].a){
			if(t[i].c!=no[i].c) res+=t[i].a-no[i].a;
			t[i].a=no[i].a;
		}
	}
	for(int i=0;i<n;i++){
		if(no[i].c==t[i].c){
			no.erase(no.begin()+i);
			t.erase(t.begin()+i);
			i--,n--;
		}
	}
	for(int i=0;i<n;i++){
		if(t[i].c!=no[i].c) {
			res+=t[i].a;
		}
	}
	cout<<res/2;
	return 0;
}
