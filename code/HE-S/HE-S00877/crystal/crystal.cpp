#include<bits/stdc++.h>
using namespace std;
long long n,m,num,ans,maxn;
bool flag;
struct my{
	long long date;
	long long sub;
}a[500010];
bool cmp(my x,my y){
	return x.date<y.date;
}
int main (){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].date;
		if(i>a[i].date||i<a[i].date){
			flag=true;
		}
	}
	if(!flag){
		long long s=0;
		for(int i=1;i<=n;i++){
			s+=i;
			if(s>m){
				cout<<i-1;
				return 0;
			}
		}
		cout<<n;
		return 0; 
	}
	sort(a+1,a+1+n,cmp);
	a[1].sub=a[2].date-a[1].date;
	a[n].sub=a[n].date-a[n-1].date;
	priority_queue<pair<long long,int> >que ;
	priority_queue<long long> q;
	que.push({-a[1].sub,1});
	que.push({-a[n].sub,n});
	for(int i=2;i<n;i++){
		a[i].sub=min((a[i].date-a[i-1].date),(a[i+1].date-a[i].date));
		que.push({-a[i].sub,i});
	}
	q.push(a[que.top().second].date);
	num++;
	que.pop();
		while(!que.empty()){
		cout<<a[que.top().second].date<<endl;
		que.pop();
	}
	while(!que.empty()){
		long long x=-que.top().first;
		long long id=que.top().second;
		que.pop();
		int maxn=q.top();
		q.pop(); 
		int maxn2=q.top();
		if(a[id].date<=maxn){
			if(m-=(maxn-a[id].date)>=0){
				num++;
				m-=(maxn-a[id].date);
				q.push(a[id].date);
				q.push(maxn);
			}else{
				if(m+(maxn-maxn2)*num-(maxn2-num)>=m){
					m+=(maxn-maxn2)*num-(maxn2-num);
					q.push(a[id].date);
				}
			}
		}else{
			if(m-=(a[id].date-maxn)>=0){
				num++;
				m-=(a[id].date-maxn);
				q.push(a[id].date);
				q.push(maxn);
			}
		}
	}
	cout<<num;
	return 0;
}
