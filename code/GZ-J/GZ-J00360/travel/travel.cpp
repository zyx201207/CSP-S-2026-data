
    //GZ-J00360贵阳市观山湖区第一高级中学祝廷嘉
    #include<bits/stdc++.h>
    using namespace std;

    string a1,a2,b1,b2;
    int k,v;
    main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>a2>>b1>>b2;
    k=a2[2]-'A';
    v=b2[2]-'A';
    if(a1[0]==b1[0]&&a1[1]==b1[1]){
        cout<<1;
        if(a2[0]==b2[0]&&a2[1]==b2[1]){
        cout<<1;
        if(a2[2]<='c'&&b2[2]<='c'){
        cout<<1;
        if(k-1==v||k+1==v||a2[2]=='D'&&b2[2]=='F'||a2[2]=='F'&&b2[2]=='D'){
            cout<<1;
        }
    }
    else if(a2[2]>'c'&&b2[2]>'c'){
        cout<<1;
        if(k-1==v||k+1==v||a2[2]=='D'&&b2[2]=='F'||a2[2]=='F'&&b2[2]=='D'){
            cout<<1;
        }
    }
        else{
            cout<<0<<0;
        }
    }
    else{
        cout<<0<<0<<0;
    }
    }
    else{
        cout<<0<<0<<0<<0;
    }


    return 0;
    }


