#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int a[N];
int cnt[N];
bool instack[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,x;
	cin>>n>>x;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		stack<int> s;
	//	memset(,0,sizeof(vis));
		memset(instack,0,sizeof(instack));
		for(int j=i+1;j<=n;j++){
			if(!instack[a[j]]){
				s.push(a[j]);
				cnt[a[j]]++;
				instack[a[j]]=1;
			}
			else{
			//	cout<<a[j]<<"\n";
				while(s.top()!=a[j]){
				//	cout<<s.top()<<" is s.top"<<"\n";
					int temp=s.top();
					s.pop();
					cnt[temp]--;
				//	cout<<"pop "<<a[j]<<" ";
					instack[a[j]]=0;
				}
			}
			
		}
	}
	for(int i=1;i<=x;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
