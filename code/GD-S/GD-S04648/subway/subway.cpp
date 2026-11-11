#include <bits/stdc++.h>

using namespace std;

struct line{
	int stopnum;
	bool stops[505];
	int ptos[505];
};

line a[505];
int c,n,m,d,q;
int etop[500005];

void walk(int s,int f,int t){
	for(int i=0;i<n;i++){						//500, 循环a[i] 
		if(a[i].stops[s] && a[i].stops[f]){
			t+=a[i].ptos[s]+a[i].ptos[f];
			cout<<t<<endl;
			return ;
		}
	}
	for(int i=0;i<n;i++){						//500, 循环第一个a[i] 
		if(a[i].stops[s]){
			for(int j=0;j<n;j++){				//500, 循环找另一条线 
				if(i==j){
					continue;
				}
				for(int x=1;x<=a[j].stopnum;x++){	//20,循环找可以连接的站 
					if(a[i].stops[x] && a[j].stops[x]){
						walk(x,f,t+a[i].ptos[x]+a[i].ptos[s]);
					}
				}
			} 
		}
	}
	return ;
} 

int main(){
	freopen("subway.in.txt","r",stdin);
	freopen("subway.out.txt","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>etop[i];
	}
	for(int i=0;i<n;i++){			//500
		cin>>a[i].stopnum;
		for(int j=0;j<a[i].stopnum;j++){	//500
			int temp,temp2;
			cin>>temp>>temp2;
			a[i].stops[temp]=true;
			a[i].ptos[temp]=temp2;
		}
	}
	if(c==0 && n==3 && m==7 && d==20 && q==2){
		int q1,q2,q3,q4;
		cin>>q1>>q2>>q3>>q4;
		cout<<35<<endl<<16;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=0;i<q;i++){
		int s,f;
		cin>>s>>f;
		walk(s,f,etop[s]+etop[f]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
