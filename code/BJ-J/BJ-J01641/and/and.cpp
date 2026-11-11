    #include<bits/stdc++.h>
    using namespace std;
    int a[10001],x,maxn,maxx;
    int main(){
        freopen("and.in","r",stdin);
        freopen("and.out","w",stdout);
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++){
            cin>>a[i];
            x=a[0];
        }
        for(int i=1;i<=m;i++){
            if(maxn<a[i]){
                maxn=a[i];
                if(maxx<a[i]&&a[i]<maxn){
                maxx=a[i];
                }
            }
            
        }
        cout<<(maxn&maxx);
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
