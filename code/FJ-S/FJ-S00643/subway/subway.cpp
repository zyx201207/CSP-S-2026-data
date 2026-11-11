#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,en[500005],t[500005][22],pos[500005][22],cntn,pt[1000005],tr[1000325][32],val[1000325],vnum;
struct plan{
	int st,ed;
}ps[100001];
struct cnt{
	long long st,ed,lth;
}cts[500005];
bool cmp(cnt v1,cnt v2){
	return v1.lth<v2.lth;
}
int root(int id){
	if (pt[id]==id||pt[id]==0){
		return id;
	}
	else{
		pt[id]=root(pt[id]);
		return pt[id];
	}
}
void ljie(int v1,int v2,int l){
	if (root(v1)!=root(v2)){
		vnum++;
		pt[root(v1)]=pt[root(v2)]=vnum;
		tr[root(v1)][0]=tr[root(v2)][0]=vnum;
		val[vnum]=l;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>en[i];
	}
	for (int i=1;i<=n;i++){
		int p1,p2,t1,t2;
		cin>>p1>>p1>>t1>>p2>>t2;
		cntn++;
		cts[cntn].st=p1;
		cts[cntn].ed=p2;
		cts[cntn].lth=t1+t2;
	}
	for (int i=1;i<=q;i++){
		cin>>ps[i].st>>ps[i].ed;
	}
	sort(cts+1,cts+cntn+1,cmp);
	vnum=cntn;
	for (int i=1;i<=cntn;i++){
		if (root(cts[i].st)!=root(cts[i].ed)){
			ljie(cts[i].st,cts[i].ed,cts[i].lth);
		}
	}
	return 0;
}
