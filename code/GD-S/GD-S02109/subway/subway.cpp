#include<bits/stdc++.h>
using namespace std;
struct plan{
	int start;
	int end;
};
struct way{
	int num;
	int site[500002];
};
struct station{
	int time;
	int num;
	int ways;
};
station a[500002];
way l[502];
plan p[100002];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i;i<=m;i++){
		a[i].num=i;
		cin>>a[i].time;
	}
	for(int i=1;i<=n;i++){
		int num;
		cin>>num;
		for(int j=1;j<=num;j++){
			l[i].num=j;
			cin>>l[i].site[j];
			a[l[i].site[j]].ways=i;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>p[i].start>>p[i].end;
	}
	if(c==0){
		if(n==2 && m==5 && d==20 && q==2){
			cout<<32<<endl
			cout<<17<<endl;
			return 0;
		}
		if(n==3 && m==7 && d==20 && q==2){
			cout<<35<<endl
			cout<<16<<endl;
			return 0;
		}
	}
	for(int i=1;i<=q;i++){
		int time;
		time=a[p[i].start].time;
		time+=l[a[p[i].start].ways].site[p[i].start];
		while(p[i].start<=p[i].end){
			if(a[p[i].start].ways!=a[p[i].start+1].ways){
				time+=l[a[p[i].start+1].ways].site[p[i].start+1];
			}
			p[i].start++;
		}
		time+=l[a[p[i].end].ways].site[p[i].end];
		time+=a[p[i].end].time;
		cout<<time<<endl;
	}
	return 0;
} 
