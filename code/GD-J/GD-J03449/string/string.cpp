#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	string t;
	string q,w;
	int s=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			t.push_back(c[i]);
		} 
	} 
	if(n==1){
		cout<<0;
		return 0;
	}
	if(t.size()%2==0){
		int b=t.size()/2;
		for(int i=0;i<=b-1;i++){
			q.push_back(t[i]);
		}
		for(int i=t.size()-1;i>=b;i--){
			w.push_back(t[i]);
		}
		if(q==w){
			cout<<0;
			return 0;
		}else{
			for(int i=0;i<=n;i++){
				if(q[i]!=w[i]){
					s++;
				}
			}
		}	
	}else if(t.size()%2!=0){
		int b=t.size()/2;
		for(int i=0;i<=b;i++){
			q.push_back(t[i]);
		}
		for(int i=t.size()-1;i>=b;i--){
			w.push_back(t[i]);
		}
		if(q==w){
			cout<<0;
			return 0;
		}else{
			for(int i=0;i<=n;i++){
				if(q[i]!=w[i]){
					s++;
				}
			}
		}	
	}
	cout<<s;
	return 0;
}

