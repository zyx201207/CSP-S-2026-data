#include<bits/stdc++.h>
using namespace std;
int n,m;
int start;
int card[500010];
int desk[500010];
int ans[300010];
int desk_x;

struct y{
	int c;
	int start;
}clan[300010]; 

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>card[i];
	}
	for(int i=1;i<=n;i++){
		desk_x=1;
		for(int j=i;j<=n;j++){
		desk[desk_x]=card[j];
		desk_x++;	
		}
//		int shunxu=1;
//	for(int o=1;o<=desk_x;o++){
//		if(desk[o]!=0&&shun[shunxu-1]!=desk[o]){
//			shun[shunxu]=desk[o];
//			shunxu++;
//		}
//	}


//	Çå½à	for(int p=1;p<=m;p++){
//			int c=0;
//			start=0;
//			for(int q=1;q<=desk_x-1;q++){
//				if(desk[q]==p){
//					c++;
//					if(c==2){
//						for(int cl=start;cl<q;cl++){
//							clan[cl]=true;
//						}
//						c=1;
//					}
//					start=q;
//				}
//			}
//
//		}
		
		for(int p=1;p<=desk_x;p++){
			clan[desk[p]].c++;
			if(clan[desk[p]].c==2){
				for(int q=clan[desk[p]].start;q<p;q++){
					if(clan[desk[q]].start==q){
						clan[desk[q]].c=0;
					}
					desk[q]=0;
				}
				clan[desk[p]].c=1;
				clan[desk[p]].start=p;
			}
			clan[desk[p]].start=p;
		}
		
		for(int k=1;k<=m;k++){
		    for(int l=1;l<=desk_x;l++){
			    if(desk[l]==k){
			    	ans[k]++;
			    }
		    }
		}
//	/////	
//	for(int p1=1;p1<=desk_x-1;p1++){
//		cout<<desk[p1]<<" ";
//	}
//	cout<<"|";
//	/////
//	/////
//	for(int p1=1;p1<=m;p1++){
//		cout<<ans[p1]<<" ";
//	}
//	cout<<endl;
//	/////
		

		for(int g=1;g<=n;g++) desk[g]=0; 
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

