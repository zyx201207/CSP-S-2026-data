//GZ-J00205 贵阳市第十八中学 钟承邑
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[500005];
bool isEnd(int x[],int n){
	int sum=0;
    for(int i=1;i<=n;i++){
        if(x[i]) sum++;
    }
    if(sum==1) return true;
    return false;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
        cin>>a[i];
	}
	int nowju=0;
	int c[500005];
	while(!isEnd(a,n)){
        nowju++;
        int nowbsize=0;
        for(int i=1;i<=nowju;i++){
            b[i]=a[i];
            nowbsize++;
        }
        for(int i=1;i<=n;i++){
            int nownum=a[i];
            a[i]=0;
            for(int j=nowbsize;j>=1;j--){
                if(b[j]==nownum){
                    for(int k=nowbsize;k>=j;k--){
                        b[k]=0;
                    }
                }
                nowbsize++;
                b[nowbsize]=nownum;
            }
        }
        c[b[nowbsize]]++;
	}
	for(int i=1;i<=m;i++){
        if(c[i]==i) cout<<c[i]<<" ";
	}
	puts("");
    return 0;
}
