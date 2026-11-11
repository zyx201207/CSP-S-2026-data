#include<bits/stdc++.h>
using namespace std;
long long n,d;
vector<long long>s;
long long dij(int st){
    vector<long long>dis(n,LLONG_MAX),cnt(n);
    //{w,v};
    long long res=0;
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;
    q.push({0LL,st});
    while(!q.empty()){
        pair<long long,int>tp=q.top();
        q.pop();
        if(dis[tp.second]<tp.first)continue;
        dis[tp.second]=tp.first;
        int pos=tp.second-1;
        while(pos>=0){
			if(s[tp.second]-s[pos]<=d){
				q.push({tp.first+1,pos});
			}
			pos--;
		}
		pos=tp.second+1;
		while(pos<n){
			if(s[pos]-s[tp.second]<=d){
				q.push({tp.first+1,pos});
			}
			pos++;
		}
    }
    q.push({0LL,st});
    while(!q.empty()){
        pair<long long,int>tp=q.top();
        q.pop();
        if(dis[tp.second]<tp.first)continue;
        if(dis[tp.second]==tp.first)cnt[tp.second]++;
        dis[tp.second]=tp.first;
        int pos=tp.second-1;
        while(pos>=0){
			if(s[tp.second]-s[pos]<=d){
				q.push({tp.first+1,pos});
			}
			pos--;
		}
		pos=tp.second+1;
		while(pos<n){
			if(s[pos]-s[tp.second]<=d){
				q.push({tp.first+1,pos});
			}
			pos++;
		}
    }
    for(int i=0;i<n;i++){
		if(cnt[i]==2)res++;
	}
    return res;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int tmptmptmp,t;
    cin>>tmptmptmp>>t;
    while(t--){
		cin>>n>>d;
		s.clear();
		s.resize(n);
		for(int i=0;i<n;i++){
			cin>>s[i];
		}
		sort(s.begin(),s.end());
		long long ret=0;
		for(int i=0;i<n;i++)ret+=dij(i);
		cout<<ret/2<<endl;
	}
    return 0;
}
