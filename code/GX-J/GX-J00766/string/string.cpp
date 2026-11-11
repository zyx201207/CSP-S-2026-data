#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a;
	char ch;
};
node d[200010];
node w[100010];
node v[100010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long sum=0;
	for(int i=1;i<=n;i++){
		cin>>d[i].a>>d[i].ch;
		sum+=d[i].a;
	}
	long long tot=0;
	int f=0;
	int wl=0;
	int vl=0;
	for(int i=1;i<=n;i++){
		if(tot+d[i].a>sum/2&&f!=1){
			int x=sum/2-tot;
			int y=tot+d[i].a-sum/2;
			if(x!=0){
				wl++;
				w[wl].a=x;
				w[wl].ch=d[i].ch;
			}
			if((sum%2==0&&y==1)||y>1){
				vl++;
				v[vl].a=y;
				v[vl].ch=d[i].ch;
				if(sum%2==1)
					v[vl].a--;
			}
			f=1;
		}
		else if(f==0){
			wl++;
			w[wl].a=d[i].a;
			w[wl].ch=d[i].ch;
		}
		else if(f==1){
			vl++;
			v[vl].a=d[i].a;
			v[vl].ch=d[i].ch;
	    }
	    tot+=d[i].a;
	}
	int i=1,j=vl;
	long long nw=w[1].a,nv=v[vl].a;
	long long ans=0;
	while(j>=1&&i<=wl){
		if(nw>nv){
			if(w[i].ch!=v[j].ch)
				ans+=nv;
			j--;
			nw-=nv;
			nv=v[j].a;
		}
		else if(nw==nv){
			if(w[i].ch!=v[j].ch)
				ans+=nv;
			i++;
			j--;
		    nw=w[i].a;
			nv=v[j].a;
		}
		else{
			if(w[i].ch!=v[j].ch)
				ans+=nw;
			i++;
			nv-=nw;
			nw=w[i].a;
			
	    }
	}
	cout<<ans;
	return 0;
}
