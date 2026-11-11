#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c, n, m, d, q;
    scanf("%d %d %d %d %d ",&c,&n,&m,&d,&q);
    vector<int>w(n,0);
    for(int i=0;i<m;i++){
    	scanf("%d",&w[i]);
	}
	int k;
	scanf("%d",&k);
	vector<int>cc(k,0);
	for(int i=0;i<k;i++){
		scanf("%d",&cc[i]);
	}
	scanf("%d",&k);
	vector<int>cnm(k,0);
	for(int i=0;i<k;i++){
		scanf("%d",&cnm[i]);
	}//É¶ÆÆBÌâ°¡¸ù±¾Ã»Ë¼Â·£¨ÆäÊµÊÇÌ«ÈÆÁË¸ø×Ô¼ºÅª²»Ã÷°×ÁË£©Äã¹»ÁË:( ^-^ T-T _ !_?  °¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡!!!!!!!!!!!!!!!!!!!!!!!!!! 
	while(q--){
		printf("%d",cnm[7]+cc[q]+w[7]+cc[7]+w[q]);
	}
	return 0;
}

