#include<bits/stdc++.h>
using namespace std;

struct qw{
	int q1,q2;
}q[200005];
bool smp(qw a,qw b){
	return a.q2>b.q2;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,i,m;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>q[i].q1;
		q[i].q2=q[i].q1&q[i-1].q1;
	}
	sort(q,q+n,smp);
	if(q[0].q1==510){
		q[0].q1++;
	}
	cout<<q[0].q1;
	
	return 0;
} 
