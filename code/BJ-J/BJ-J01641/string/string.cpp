    #include<bits/stdc++.h>
    using namespace std;
    string a[100001];
    int main(){
        freopen("string.in","r",stdin);
        freopen("string.out","w",stdout);
        int n;
        cin>>n;
         for(int i=0;i<=n;i++){
                cin>>a[i];
         }
         for(int i=0;i<n;i++){
            for(int j=n;j>0;j--){
                if(a[i]==a[j]){
                    cout<<"0"<<endl;
                    return 0;
                }
            }
         }
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
