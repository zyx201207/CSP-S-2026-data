#include <bits/stdc++.h>
using namespace std;
struct station{
	int numsta;
	int w;
	int t;
	int djg;
};
struct line{
	int linnum;
	int sumsta;
	station o[88]; 
};
struct jh{
	int start;
	int end;
};
int n,c,m,d,q;
line fre[887];
station deanot[88];
jh ghu[88];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >>q;
	for(int i = 1;i <= m;i++){
		cin >> deanot[i].w;
		deanot[i]. numsta = i;
	}
	for(int i= 1;i <= n;i++){
		fre[i].linnum = i;
		cin >> fre[i].sumsta;
		for(int l= 1;l <= fre[i].sumsta;l++){
			cin >> fre[i].o[l].numsta >> fre[i].o[l].t;
			fre[i].o[l].djg = i;
		}
	}
	for(int i = 1;i <= q;i++){
		cin >> ghu[i].start >> ghu[i].end;
	}
	for(int i = 1; i<= q;i++){
		int sum = 0;
		int yq = 0,xq = 0,xz = 0,yz = 0,gt = 0,r11=0,r22 = 0,ju = 0;;
		for(int j =1;j <= n;j++){
			for(int k= 1;k <= fre[j].sumsta;k++){
				 if(fre[j].o[k].numsta == ghu[i].start) {
				 	xq = j; 
				 	 r11 = k;
				 	 
				 } 
				 if(fre[j].o[k].numsta ==ghu[i].end) {
					xz = j;
					 r22 = k;
					
				} 
				 if(r11!=0 && r22!=0){
				 	ju = 1;
				 	break;
				 }
			}
			if(ju == 1){
				break;
			}
		}
		
		int flag = 0,gt1 = 0,gt2=0;
		if(xq != xz){
			for(int d = 1; d <= fre[xq].sumsta;d++ ){
				for(int h = 1; h <= fre[xz].sumsta;h++){
					if (fre[xq].o[d].numsta == fre[xz].o[h].numsta){
						
						gt1 =d;
						gt2 = h;
						flag = 1;
						break;
					}
				}
				if(flag == 1){
					break;
				}
			}
			 
			for(int d = r11; d <= gt1;d++ ){
				sum += fre[xq].o[d].t;
				
			}
			
			for(int e = gt2; e <= r22;e++){
				sum += fre[xz].o[e].t;
				
			}
			
			sum+=deanot[ghu[i].start].w + deanot[ghu[i].end].w;
			cout << sum << endl ;
		}else{
			for(int u = r11;u <= r22;u++){
				sum+=fre[xz].o[u].t;
			}
			sum+=deanot[ghu[i].start].w + deanot[ghu[i].end].w;
			cout << sum << endl;
		}
		
		
		
		
		
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}







//0 2 5 20 2
// 4 1 9 2 5
// 3 1 5 2 7 4 6
// 3 2 3 3 4 5 7
// 1 3
// 1 2





