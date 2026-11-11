#include<bits/stdc++.h>
//何为大心脏？我在还剩四分钟的时候修改了核心代码 
using namespace std;
int n,m,a[500010],ton[500010],t[500010],mn[500010];
void pm(int k){
	for(int i=1;i<=k;i++){
		cout<<mn[i];
	}
	cout<<k<<endl;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int k=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++)mn[j]=0;
		for(int j=1;j<=n;j++)t[j]=0; 
		k=0;
		for(int j=i;j<=n;j++){
			k++;
			if(t[a[j]]==1){
				for(int l=k;l>1;l--){
					t[mn[l]]=0;
					if(mn[l]==a[j]){
						break;
					}
					cout<<'-';
					k--;
					mn[l]=0;
					
				}
				t[a[j]]=1;
			}
			cout<<'+';
			t[a[j]]=1;
			mn[k]=a[j];
			pm(k);
		}
			cout<<i<<endl<<endl;
		for(int j=1;j<=k;j++){
			ton[mn[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
			cout<<ton[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);


	//考生注意事项 10. 考生不能在注释中写侮辱性话语、歌词、诗词、散文等与考试无关的话语，若有违反可能会收到取消成绩或以上处分。
	//[思考.ing] 那我偏要写 
	
	//左手离散右手桶，加上记忆化，轮椅懂？ 
	// Hello, the friends from “迷惑行为” . My luogu's name is: oscarbearlzl 
	
	//Piggaad no kill me! I no money! I only one RP++ [doge]
	return 0;
}
