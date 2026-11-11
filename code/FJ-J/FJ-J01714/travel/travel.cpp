#include<cstdio>
char cr[5],sr[5],cx[5],sx[5];

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	scanf("%s%s%s%s",cr+1,sr+1,cx+1,sx+1);
	if(cr[1]==cx[1] && cr[2]==cx[2]){
		printf("1");
		if(sr[1]==sx[1] && sr[2]==sx[2]){
			printf("1");
			if(('A'<=sr[3] && sr[3]<='C' && 'A'<=sx[3] && sx[3]<='C') || ('D'<=sr[3] && sr[3]<='F' && 'D'<=sx[3] && sx[3]<='F')){
				printf("1");
				if(sr[3]+1==sx[3] || sx[3]+1==sr[3]) printf("1");
				else printf("0");
			}else printf("00");
		}else printf("000");
	}else printf("0000");
	return 0;
} 
