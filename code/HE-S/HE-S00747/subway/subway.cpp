#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,cnt,x,y,zdxl,cz; 
int ml[500004];
int k[505];

bool lla,llb,l,fl;
struct f{
	int xi,yi;
};
struct v{
	int a,t;
};
v dl[505][50];
f ql[100007];
void Input(){
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)cin>>ml[i];
	for(int i=0;i<n;i++){
		cin>>k[i]; 
		for(int j=0;j<k[i];j++){
			cin>>dl[i][j].a>>dl[i][j].t;
			dl[i][j].a--;
		}
	}
}


int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	Input();
	
	for(int T=0;T<q;T++){
		cin>>ql[T].xi>>ql[T].yi;
		x=ql[T].xi - 1;
		y=ql[T].yi - 1;
		cnt=0;	
		cnt+=ml[x]+ml[y];
		l=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<k[i];j++){
				if(x==dl[i][j].a )lla=1;
			}
			for(int j=0;j<k[i];j++){
				if(y==dl[i][j].a )llb=1;
			}
			if(lla&&llb){
				l=1;
				zdxl=i;
			}
			lla=0,llb=0;
		}
		//²»ÐèÒª»»³Ë 
		if(l){
			cnt+=dl[zdxl][x].t +dl[zdxl][y].t ;
			cout<<cnt<<endl;
		}
		else{
			for(int i=0;i<n;i++){
				for(int j=0;j<k[i];j++){
					if(x==dl[i][j].a )cz=0;
					else cz=1;
				}
			}
			for(int i=0;i<n;i++){
				for(int j=0;j<k[i];j++)
				if(dl[1][i].a ==dl[0][j].a ){
					if(cz==0){
						cnt+=dl[0][j].t +dl[1][i].t ;
						cnt+=dl[0][x].t+dl[1][y].t;
						
					}
					else{
						cnt+=dl[0][j].t+dl[1][i].t;
						cnt+=dl[1][x].t+dl[0][y].t;
						
					}
				}
			}
			cout<<cnt<<endl; 
		}
		
	}
	return 0;
} 

//0 2 5 20 2 4 1 9 2 5 3 1 5 2 7 4 6 3 2 3 3 4 5 7 1 3 1 2
