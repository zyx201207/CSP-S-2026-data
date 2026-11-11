#include <bits/stdc++.h>
using namespace std;

struct arry{
	char ac;
	long long x;
}a[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long num;
	cin>>num;
	char suc[num+5];
	long long have[num+5],cnt=0;
	have[0]=0;
	for(int i=1;i<=num;i++){
		char c;
		long long n;
		scanf("%lld",&n);
		cin>>c;
		cnt+=n;
		suc[i]=c;
		have[i]=n;
	}
	bool flag1=false,flag2=false;
	long long sux=0,suy=0,cnt2=0,al=0,l=0,r=0,ans=0;
	if(cnt%2==0){
		sux=cnt/2;
		suy=cnt/2+1; 
		for(int i=1;i<=num;i++){
			cnt2+=have[i];
			if(cnt2>=sux and cnt2>=suy and flag1==false and flag2==false){
				a[++al].ac=suc[i];
				a[al].x=sux-(cnt2-have[i])-1;
				if(a[al].x==0) al--; 
				a[++al].ac=suc[i];
				a[al].x=1;
				l=al-1;
				a[++al].ac=suc[i];
				a[al].x=1;
				r=al+1;
				a[++al].ac=suc[i];
				a[al].x=cnt2-suy;
				if(a[al].x==0) al--; 
				flag1=true;
				flag2=true;
				continue;
			}
			if(cnt2>=sux and flag1==false){
				a[++al].ac=suc[i];
				a[al].x=sux-(cnt2-have[i])-1;
				if(a[al].x==0) al--; 
				a[++al].ac=suc[i];
				a[al].x=1;
				l=al-1;
				a[++al].ac=suc[i];
				a[al].x=cnt2-sux;
				if(a[al].x==0) al--;
				ans++;
				flag1=true; 
			}else if(cnt2>=suy and flag2==false){
				a[++al].ac=suc[i];
				a[al].x=suy-(cnt2-have[i])-1;
				if(a[al].x==0) al--; 
				a[++al].ac=suc[i];
				a[al].x=1;
				r=al+1;
				a[++al].ac=suc[i];
				a[al].x=cnt2-suy;
				if(a[al].x==0) al--; 
				flag2=true;
			}else{
				a[++al].ac=suc[i];
				a[al].x=have[i];
			}
		}
	}else{
		sux=cnt/2+1;
		for(int i=1;i<=num;i++){
			cnt2+=have[i];
			if(cnt2>=sux and flag1==false){
				a[++al].ac=suc[i];
				a[al].x=sux-(cnt2-have[i])-1;
				if(a[al].x==0) al--; 
				a[++al].ac=suc[i];
				a[al].x=1;
				l=al-1;
				r=al+1;
				a[++al].ac=suc[i];
				a[al].x=cnt2-sux;
				if(a[al].x==0) al--; 
				flag1=true;
			}else{
				a[++al].ac=suc[i];
				a[al].x=have[i];
			}
		}
	}
	//cout<<al<<" "<<l<<" "<<r<<" ";
	a[0].x=0;
	a[al+1].x=0;
	long long sul=a[l].x,sur=a[r].x;
	while(sul!=0 or sur!=0){
		if(a[l].ac!=a[r].ac){
			if(sul>sur){
				sul-=sur;
				ans+=sur;
				r++;
				sur=a[r].x;
			}else if(sur>sul){
				sur-=sul;
				ans+=sul;
				l--;
				sul=a[l].x;
			}else if(sul==sur){
				ans+=sul;
				l--;
				r++;
				sul=a[l].x;
				sur=a[r].x;
			}
		}else if(a[l].ac==a[r].ac){
			if(sul>sur){
				sul-=sur;
				r++;
				sur=a[r].x;
			}else if(sur>sul){
				sur-=sul;
				l--;
				sul=a[l].x;
			}else if(sul==sur){
				l--;
				r++;
				sul=a[l].x;
				sur=a[r].x;
			}
		}
	}
	cout<<ans;
	return 0;
} 
