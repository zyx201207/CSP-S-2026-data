#include<bits/stdc++.h>

using namespace std;
int s[90000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int k=1;
	for(int i=1;i<=n;i++){
		int q;
		char p;
		cin>>q>>p;
		for(int j=k;j<=k+p;j++){
			s[j]=(int)p;
		}
		k+=q;
	}
	int ans=0;
	int l=1,r=k;
	while(l<=r){
		if(s[l]!=s[r]) ans++;
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}
/*
#include<bits/stdc++.h>

using namespace std;
struct ge{
	int shu;
	char type;
}a[200010];
ge b[200010];
int n;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int p;
		char q;
		cin>>p>>q;
		a[i].shu=p;
		a[i].type=q;
	}
	int z=1;
	char p=a[1].type;
	b[z].type=p;
	for(int t=1;t<=n;t++){
		if(p!=a[t].type){
			z++;
			b[z].type=a[t].type;
			p=a[t].type;
		}
		b[z].shu+=a[t].shu;
	}
	long long ans=0;
	int l=1,r=z,qian=0;
	while(l<=z){
		ge maxn=a[l];
		ge minn=a[r];
		if(maxn.shu<minn.shu){
			ge q=maxn;
			maxn=minn;
			minn=q;
		}
		if(maxn.type!=minn.type){
			ans+=minn.shu;
			int k=maxn.shu-minn.shu;
			while(a[r].shu<=k){
				r--;
				k-=a[r].shu;
				if(a[r].type!=maxn.type) ans+=a[r].shu
			}
			qian=a[r].shu-k;
			l++;
		}
	}
	return 0;
}*/
