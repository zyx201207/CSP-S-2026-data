#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n];
	vector<long long>h(m+1,0),p(m+1,0);
	stack<long long>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(long long i=0;i<n;i++){
		for(long long j=i;j<n;j++){
			if(h[a[j]]>0){
				while(!s.empty()&&s.top()!=a[j]){
					h[s.top()]--;
					s.pop();
				}
				if(!s.empty()){
					s.pop();
					s.push(a[j]);
				}
			}
			else{
				h[a[j]]++;
				s.push(a[j]);
			}
		}
		for(long long c=1;c<=m;c++){
			if(h[c]>0){
				p[c]++;
				h[c]=0;
			}
		}
		while(!s.empty()){
			s.pop();
		}
	}
	for(long long d=1;d<=m;d++){
		cout<<p[d];
		if(d!=m){
			cout<<" ";
		}
	}
	return 0;
}
