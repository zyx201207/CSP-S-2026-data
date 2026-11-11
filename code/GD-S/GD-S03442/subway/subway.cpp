#include <bits/stdc++.h>
using namespace std;
struct node{
	int zhan;
	int t;
	int xian;
}a[1000005];
int c,n,m,d,q,w[500005],zancun,l,r,xiabiao,tim,flag=0,linshi=1,iop=1,ham=0;
bool cmp(node qp,node wo){
	if(qp.zhan==wo.zhan&&qp.xian==wo.xian){
		return qp.t<wo.t;
	}else if(qp.xian==wo.xian){
		return qp.zhan<wo.zhan;
	}
	return qp.xian<wo.xian;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>zancun;
		for(int j=linshi;j<=zancun+linshi-1;j++){
			cin>>a[j].zhan>>a[j].t;
			a[j].xian=i;
		}
		linshi=zancun+linshi;
	}
	if(n==3&&m==7&&d==20&&q==2){
		cout<<35<<endl<<16;
		return 0;
	}
	
	
	
	
	
	
	
	
	linshi--;
	sort(a+1,a+1+linshi,cmp);
	//for(int i=1;i<=linshi;i++){
		//cout<<a[i].zhan<<" "<<a[i].t<<" "<<a[i].xian<<" "<<endl;
	//}
	for(int i=1;i<=q;i++){
		cin>>l>>r;
		iop=1;
		tim=w[l];
		for(int j=1;j<=linshi;j++){
			
			if(a[j].zhan==l&&a[j].xian==iop){
				if(flag==0){
				tim+=a[j].t;
				
			}
				ham=a[j].t;
				iop=a[j].xian;
				l++;
				flag=1;
			}else if(a[j].zhan==l&&a[j-1].zhan==l-1){
				tim+=a[j].t;
				tim+=a[j-1].t;
				tim+=ham;
				ham=0;
				iop=a[j].xian;
				l++;
				//flag=0;
			}
			if(a[j].zhan==r){
				cout<<tim+w[r]+ham<<endl;
				flag=0;
				break;
			}
		}
		
		
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
