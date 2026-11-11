#include<bits/stdc++.h>
using namespace std;


int m,n,maxdig=-1,candcnt;
bool num[1000000][32];
int cand[1000000];
int winner[1000000];
bool ans[32];
int lastpin;

int Trans10To2(int r,int a){
	int u=0,tmp;
	while(a>0){
		tmp=a%2;
		if(tmp==1) num[r][31-u]=true;
		u++;
		a/=2;
	}
	return u;
}

void scan(){
	int pin=31-maxdig;
	for(pin;pin<=31;pin++){//找同位上至少有m个1的最高位数 
		int tmp=0;
		for(int i=1;i<=n;i++){
			tmp+=(int)(num[i][pin]);
		}
		if(tmp>=m) break;
	}
	for(int i=1;i<=n;i++){//将此时第pin位为1的数加入待选数组 
		if(num[i][pin]){
			cand[candcnt]=i;
			candcnt++;
		}
	}
	
	int crrcnt=candcnt;
	for(pin;pin<=31&&crrcnt>m;pin++){//继续遍历，先有0先淘汰 
		for(int i=0;i<=candcnt;i++){
			if(cand[i]==-1) continue;
			if(!num[cand[i]][pin]){
				cand[i]=-1;
				crrcnt--;
			}
			if(crrcnt==m) break;
		}
	}
	pin--;
	lastpin=pin;
	for(int i=0,k=1;i<=candcnt&&k<=m;i++){//整理最终选取的数的组合 
		if(cand[i]!=-1){
			winner[k]=cand[i];
			k++;
		}
	}
	
	for(pin;pin<=31;pin++){//位运算 
		ans[pin]=true;
		for(int i=1;i<=m;i++){
			if(num[winner[i]][pin]==false){
				ans[pin]=false;
				break;
			}
		}
	}
}

int Trans2To10(){
	int ans10=0;
	for(int i=31,j=0;i>=lastpin;i--,j++){
		if(ans[i]) ans10+=pow(2,j);
	}
	return ans10;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	cin>>n>>m;
	int k;
	for(int i=1;i<=n;i++){
		cin>>k;
		int y=Trans10To2(i,k);
		if(y>maxdig) maxdig=y;
	}
	scan();
	cout<<Trans2To10();
}
