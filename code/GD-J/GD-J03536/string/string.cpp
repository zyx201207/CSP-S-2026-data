#include<bits/stdc++.h>
#define int long long
using namespace std;
int len[200005],lens[200005];
int sum=0;
int n,ans=0;
char c[200005];
string str="";
void ans2(){
	int temp=0,v=0;
	while(temp<=sum/2){
		v++;
		temp+=len[v];
	}
	int tx=(sum/2)-lens[v-1],ty=len[v]-tx,tz=tx-ty,vl=v,vr=v,flag=0,sx=0,sy=0,cntx=1,cnty=1;
	if(sum%2==1){
		ty--;
		tz++;
		flag++;
	}
	while(tx+ty+flag<sum){
		//cout<<tx<<' '<<ty<<' '<<tz<<endl;
		if(tz>0){
			if(ty-sy+tz>len[vr] || cnty==1){
				vr++;
				if(cnty==1) sy+=ty;
				else sy+=len[vr-1];
			}
			cnty++;
			if(c[vr]!=c[vl]) ans+=abs(tz);
			ty+=abs(tz);
		}
		else if(tz<0){
			if(tx-sx+tz>len[vl] || cntx==1){
				vl--;
				if(cntx==1) sx+=tx;
				else sx+=len[vl+1];
			}
			cntx++;
			if(c[vl]!=c[vr]) ans+=abs(tz);
			tx+=abs(tz);
		}
		else{
			if(tx-sx+tz==len[vl] || cntx==1){
				vl--;
				if(cntx==1) sx+=tx;
				sx+=len[vl+1];
			}
			cntx++;
			tx+=len[vl]-(tx-sx);
		}
		tz=tx-ty;
	}
	//cout<<tx<<' '<<ty<<' '<<tz<<endl;
	cout<<ans;
	return ;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	int maxlen=-1;
	for(int i=1;i<=n;i++){
		scanf("%d %c",&len[i],&c[i]);
		sum+=len[i];
		lens[i]=lens[i-1]+len[i];
		maxlen=max(maxlen,len[i]);
	}
	//cout<<sum<<endl;
	if((n>10 && n<=2000 && maxlen>1e5) || (n<=200005 && n>2000 && maxlen>1000) || maxlen>1e8) ans2();
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=len[i];j++){
				str+=c[i];
			}
		}
		//cout<<str;
		int l=(sum+1)/2-1,r=(sum+1)/2-1;
		if(sum%2==0) r++;
		while(l>0 && r<sum){
			l--;
			r++;
			if(str[l]!=str[r]) ans++;
			//cout<<str[l]<<' '<<str[r]<<endl;
		}
		cout<<ans;
	}
	return 0;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
