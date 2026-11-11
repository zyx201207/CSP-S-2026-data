#include<cstdio>
#include<vector>
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int x,y;
	scanf("%d%d",&x,&y);
	std::vector<int> t(x+1,-1);
	std::vector<int> z(y+1,0);
	for(int a=1;a<=x;a++){
		scanf("%d",&t[a]);
	}
	for(int a=1;a<=x;a++){
		std::vector<int> now;
		for(int r=a;r<=x;r++){
			bool yes=1;
			for(unsigned int w=0;w<now.size();w++){
				if(now[w]==-1) continue;
				if(now[w]==t[r]){
					yes=0;
					for(unsigned int e=w+1;e<now.size();e++){
						z[now[e]]--;
						now[e]=-1;
					}
				}
			}
			if(yes){
				now.push_back(t[r]);
				z[t[r]]++;
			}
//			printf("a");
//			for(unsigned int e=0;e<now.size();e++){
//				printf("%d ",now[e]);
//			}
//			printf("\nb");
//			for(int e=1;e<=y;e++){
//				printf("%d ",z[e]);
//			}
//			printf("\n");
		}
	}
	for(int a=1;a<=y;a++){
		printf("%d ",z[a]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
