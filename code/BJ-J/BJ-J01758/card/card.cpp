#include <iostream>

using namespace std;

int main(){
	freopen("card.in" ,"r" ,stdin);
	freopen("card.out" ,"w" ,stdout);
	int n ,m;
	int a[500005] ,b[300005] ,e[200005] ,ans[300005];
	cin >> n >> m;
	for(int i=1; i<=m; i++){
        //b[i]=0;
        ans[i]=0;
	}
	for(int i=1; i<=n; i++){
        cin >> e[i];
	}
	for(int q=1; q<=n; q++){
        for(int i=1; i<=n; i++){
            b[i]=0;
            a[i]=e[i];
            //ans[i]=0;
        }
        for(int i=q; i<=n; i++){
            ans[a[i]]++;
            if(b[a[i]]==0){
                b[a[i]]=i;
            }
            else{
                for(int j=b[a[i]]; j<i; j++){
                    ans[a[j]]--;
                    b[a[j]]=0;
                    a[j]=-1;
                }
                b[a[i]]=i;
            }
        }
	}
	for(int i=1; i<=m; i++){
        cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}
