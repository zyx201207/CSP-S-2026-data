#include<bits/stdc++.h>
using namespace std;
int n;
stack <char> s;
long long a[200005];
char c[200005];
long long p=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		p+=a[i];
	}
//	cout<<x<<"\n\n";
	int t=0,f=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s.push(c[i]);
			if(t==p/2){
				f=1;
				break;
			}
			t++;
		}
		if(f==1){
			break;
		}
	}
	t=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			t++;
			if(t<=p/2){
				continue;
			}
			char q=c[i];
			if(s.top()==q){
				s.pop();
			}
		}
	}
	cout<<s.size();
	return 0;
}
