#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005],b[100005];
string s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int sum=0;sum<n;sum++){
		string s;
		for(int i=sum;i<n;i++){
		if(!(s.empty())){
			int len=s.size(),d;
			bool b=1;
			for(int j=0;j<len;j++){
				if(b==0){
					s.erase(s.begin()+d);
					continue;
				}
				if(s[j]==a[i]){
					b=0;
					d=j;
					s.erase(s.begin()+d);
					continue;
				}
			}
			s.insert(s.end(),a[i]);
		}
		else s.insert(s.end(),a[i]);
		}
		int s1=0;
		for(;s1<s.size();s1++);
		b[s1]++;
	}
	for(int i=1;i<m;i++) cout<<b[i]<<' ';
	return 0;
}
