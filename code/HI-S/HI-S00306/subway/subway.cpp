#include<bits/stdc++.h>
using namespace std;
int sub[10005];
int way[10005][10005];
int me1,me2,me3,me4=999999999999;
int st,end;
long long tim;
long long m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=0,n=0;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>sub[i];
	}
	for(int i=0;i<n;i++){
		cin>>way[i][0];
		for(int j=1;j<way[i][0]*2;j+=2){
			cin>>way[i][j];
			cin>>way[i][j+1];
		}
	}
	for(int i=0;i<q;i++){
		cin>>st>>end;
		tim+=sub[st];
		for(int j=0;j<n;j++){
			for(int p=1;p<=way[j][0];p+=2){
				if(way[j][p]==st){
					me1=j;
					me2=way[j][p+1];
					break;
				}
			}
			if(me2<me4&&me1!=me3){
				me4=me2;
				me3=me1;
			}
		}
		tim+=me4;
		me4=9999999999;
		for(int j=0;j<n;j++){
			int cnt=st+j;
			for(int p=1;p<=way[j][0];p+=2){
				if(way[j][p]==cnt){
					me1=j;
					me2=way[j][p+1];
					if(me2>me4&&me1!=me3){
						me4=me2;
						me3=me1;
					}
				}
				tim+=me4;
				cnt++;
			}
		}
		tim+=sub[end];
		cout<<tim<<endl;
		tim=0;
	}
	return 0;
}

