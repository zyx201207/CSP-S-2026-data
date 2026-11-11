#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ovo ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define N 500050
ll c,n,m,d,q,num,tot;
bool tmt[220][4];
//ll head[N],to[N*2],nxt[N*2],va[N*2],ik[4];
ll time1[220],time2[4][220],ik[4][220];
int main(){
	ovo;
	freopen("subway.in","r",stdin);
 	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c>=0&&c<=3){
		for(int i=1;i<=m;i++)cin>>time1[i];
		for(int i=1;i<=3;i++){
			for(int j=1;j<=230;j++)time2[i][j]=1000000009;
		}
		for(int i=1;i<=n;i++){
			int k=0;
			cin>>k;
			ik[i][0]=k;
			for(int j=1;j<=k;j++){
				int l=0;
				cin>>l;
				ik[i][j]=l;
				tmt[l][i]=1;
				cin>>time2[i][l];
			}
		}
		for(int i=1;i<=q;i++){
			int st,ed;
			cin>>st>>ed;
			ll ans=0;
			ans+=(time1[st]+time1[ed]);
			if(tmt[st][1]&&tmt[ed][1])cout<<ans<<endl;
			else if(tmt[st][2]&&tmt[ed][2])cout<<ans<<endl;
			else if(tmt[st][3]&&tmt[ed][3])cout<<ans<<endl;
			else {
				ll anss=1000000009,anss1,anss2;
				if(tmt[st][1]&&tmt[ed][2]){
					for(int j=1;j<=m;j++){
						if(tmt[j][1]&&tmt[j][2])anss=min(anss,time2[j][1]+time2[j][2]);
						if(tmt[j][1]&&tmt[j][3]){
							anss1=(time2[j][1]+time2[j][3]);
							anss2=1000000009;
							for(int ee=1;ee<=m;ee++){
								if(tmt[ee][3]&&tmt[ee][2]){
									anss2=min(anss2,time2[ee][3]+time2[ee][2]); 
								}
							}
							anss=min(anss,anss1+anss2);
						}
					}
				}
				ll ansss=1000000009,ansss1,ansss2;
				if(tmt[st][1]&&tmt[ed][3]){
					for(int j=1;j<=m;j++){
						if(tmt[j][1]&&tmt[j][3])ansss=min(ansss,time2[j][1]+time2[j][3]);
						if(tmt[j][1]&&tmt[j][2]){
							ansss1=(time2[j][1]+time2[j][2]);
							ansss2=1000000009;
							for(int ee=1;ee<=m;ee++){
								if(tmt[ee][2]&&tmt[ee][3]){
									ansss2=min(ansss2,time2[ee][3]+time2[ee][2]); 
								}
							}
							ansss=min(ansss,ansss1+ansss2);
						}
					}
				}
				ll annss=1000000009,annss1,annss2;
				if(tmt[st][2]&&tmt[ed][3]){
					for(int j=1;j<=m;j++){
						if(tmt[j][2]&&tmt[j][3])annss=min(annss,time2[j][2]+time2[j][3]);
						if(tmt[j][2]&&tmt[j][1]){
							annss1=(time2[j][1]+time2[j][2]);
							annss2=1000000009;
							for(int ee=1;ee<=m;ee++){
								if(tmt[ee][1]&&tmt[ee][3]){
									annss2=min(annss2,time2[ee][3]+time2[ee][1]); 
								}
							}
							annss=min(annss,annss1+annss2);
						}
					}
				}
				ll aanss=1000000009,aanss1,aanss2;
				if(tmt[st][2]&&tmt[ed][1]){
					for(int j=1;j<=m;j++){
						if(tmt[j][1]&&tmt[j][2])aanss=min(aanss,time2[j][1]+time2[j][2]);
						if(tmt[j][3]&&tmt[j][2]){
							aanss1=(time2[j][3]+time2[j][2]);
							aanss2=1000000009;
							for(int ee=1;ee<=m;ee++){
								if(tmt[ee][2]&&tmt[ee][1]){
									aanss2=min(aanss2,time2[ee][1]+time2[ee][2]); 
								}
							}
							aanss=min(aanss,aanss1+aanss2);
						}
					}
				}
				ll	aannss=1000000009,aannss1,aannss2;
				if(tmt[st][3]&&tmt[ed][1]){
					for(int j=1;j<=m;j++){
						if(tmt[j][1]&&tmt[j][3])aannss=min(aannss,time2[j][1]+time2[j][3]);
						if(tmt[j][3]&&tmt[j][2]){
							aannss1=(time2[j][3]+time2[j][2]);
							aannss2=1000000009;
							for(int ee=1;ee<=m;ee++){
								if(tmt[ee][2]&&tmt[ee][1]){
									aannss2=min(aannss2,time2[ee][2]+time2[ee][1]); 
								}
							}
							aannss=min(aannss,aannss1+aannss2);
						}
					}
				}
				ll aaanss=1000000009,aaanss1,aaanss2;
				if(tmt[st][3]&&tmt[ed][2]){
					for(int j=1;j<=m;j++){
						if(tmt[j][2]&&tmt[j][3])aaanss=min(aaanss,time2[j][1]+time2[j][3]);
						if(tmt[j][3]&&tmt[j][1]){
							aaanss1=(time2[j][3]+time2[j][1]);
							aaanss2=1000000009;
							for(int ee=1;ee<=m;ee++){
								if(tmt[ee][2]&&tmt[ee][1]){
									aaanss2=min(aaanss2,time2[ee][2]+time2[ee][1]); 
								}
							}
							aaanss=min(anss,anss1+anss2);
						}
					}
				}
				ans+=min(anss,min(aaanss,min(aannss,min(aanss,min(ansss,annss)))));
				cout<<ans<<endl;
			}
		}
	}
	return 0;
}
//好想笑，交了一坨啥呀 
//ganjue xiele shen me hen shi de dong xi
//有没有人统计迷惑行为啊 
