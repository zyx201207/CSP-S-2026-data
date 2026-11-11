#include<bits/stdc++.h>
using namespace std;
const int T=2e5+5;
int n,m,a[T];
string s[T];
int h=INT_MAX;
bool vis[35];
string f(int k){
	char t[35];
	int q=1;
	int e=1;
	for(; k>0; k/=2){
		t[q]=k%2;	
		q++;
	}
	h=min(h,q);
	return t;
}
vector<string> v1,v2;
void bfs(){
	while(!v1.empty()){
		v2=v1;
		int sum=0,b=0,c=0;
		for(auto r:v1){
			c++;
			string p=r;
			if(p[h]=='1'){
				sum++;
			}
			else{
				v2.erase(v2.begin()+c-b);
				b++;
			}
		}
		if(sum>=m){
			vis[h]=true;
			v1=v2;
		}
		h--;
		bfs();
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		s[i]=f(a[i]);
	}
	for(int i=1; i<=n; i++){
		v1.push_back(s[i]);
	}
	bfs();
	int k=1,l;
	for(int i=1; i<=35; i++){
		if(vis[i]==true){
			l+=k;
		}
		k*=2;
	}
	cout<<l;
	return 0;
}
