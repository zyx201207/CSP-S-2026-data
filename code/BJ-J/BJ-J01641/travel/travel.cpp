    #include<bits/stdc++.h>
    using namespace std;
    int sum;
    int main(){
        freopen("travel.in","r",stdin);
        freopen("travel.out","w",stdout);
        string a,c;
        char b,d;
        cin>>a>>b>>c>>d;
        if(a==c){
        sum+=1000;
        cout<<sum<<endl;
        }else
        {
        cout<<"0000"<<endl;
        }
        fclose(stdin)   ;
        fclose(stdout);
        return 0;
    }
