#include<bits/stdc++.h>
using namespace std;
long long n,s;
pair<long long,char> a[222222],l={0,0};
queue<pair<long long,char>>q;
string st;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){cin>>a[i].first>>a[i].second;}
	for(long long i=0;i<=ceil(n*1.0/2)-1;i++){
		if(l.first!=0){
			if(l.first>0){
				if(l.second!=a[n-i-1].second){s+=min(l.first,a[n-i-1].first);}
				if(l.first>a[n-i-1].first){
					l.first-=a[n-i-1].first;
					q.push(a[i]);
				}
				else{
					a[n-i-1].first-=l.first;
					while(!q.empty()){
						l=q.front();
						q.pop();
						if(l.second!=a[n-i-1].second){s+=min(l.first,a[n-i-1].first);}
						if(l.first>a[n-i-1].first){
							l.first-=a[n-i-1].first;
							q.push(a[i]);
							break;
						}
						else{a[n-i-1].first-=l.first;}
					}
				}
			}
			else{
				l.first*=-1;
				if(l.second!=a[i].second){s+=min(l.first,a[i].first);}
				if(l.first>a[i].first){
					l.first-=a[i].first;
					q.push(a[n-i-1]);
				}
				else{
					a[n-i-1].first-=l.first;
					while(!q.empty()){
						l=q.front();
						q.pop();
						if(l.second!=a[i].second){s+=min(l.first,a[i].first);}
						if(l.first>a[i].first){
							l.first-=a[i].first;
							q.push(a[n-1-i]);
							break;
						}
						else{a[i].first-=l.first;}
					}
				}
			}
		}
		if(a[i].second!=a[n-i-1].second){s+=min(a[i].first,a[n-i-1].first);}
		if(a[i].first>a[n-i-1].first){l.second=a[i].second;}
		else{l.second=a[n-i-1].second;}
		l.first=a[i].first-a[n-i-1].first;
	}
	if(l.first!=0){
		if(l.first>0){
			for(long long i=0;i<l.first;i++){st+=l.second;}
			while(!q.empty()){
				l=q.front();
				q.pop();
				for(int i=0;i<l.first;i++){st+=l.second;}
			}
		}
		else{
			for(long long i=0;i<l.first;i++){st+=l.second;}
			while(!q.empty()){
				l=q.front();
				q.pop();
				for(int i=0;i<l.first;i++){st+=l.second;}
			}
		}
		int m=(st.size()-1)/2;
		for(long long i=0;i<m;i++){if(st[i]!=st[m-i-1]){s++;}}
	}
	cout<<s;
	return 0;
}